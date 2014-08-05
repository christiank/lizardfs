#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <string>

#include "common/MFSCommunication.h"
#include "common/packet.h"
#include "common/serialization.h"
#include "common/sockets.h"


int main(int argc, char **argv) {
	strerr_init();
	if (argc != 6) {
		std::cerr << "Usage: " << argv[0] << " host port bytes count usleep" << std::endl;
		return 1;
	}
	uint32_t ip;
	uint16_t port;
	uint32_t size = atoi(argv[3]);
	uint32_t count = atoi(argv[4]);
	uint32_t sleep_us = atoi(argv[5]);
	eassert(tcpresolve(argv[1], argv[2], &ip, &port, 0) == 0);
	sassert(std::to_string(size) == argv[3]);

	int fd = tcpsocket();
	eassert(fd >= 0);
	tcpnodelay(fd);
	eassert(tcpnumconnect(fd, ip, port) == 0);

	std::vector<uint8_t> message;
	serializeMooseFsPacket(message, ANTOAN_PING, size);

	std::vector<uint8_t> replyBuffer(size + 8);
	uint64_t microseconds = 0;
	for (uint32_t i = 1; i <= count; ++i) {
		struct timeval start, stop;
		gettimeofday(&start, 0);
		eassert(tcptowrite(fd, message.data(), message.size(), 10000) == (ssize_t)message.size());
		eassert(tcptoread(fd, replyBuffer.data(), replyBuffer.size(), 10000) == (ssize_t)replyBuffer.size());
		gettimeofday(&stop, 0);
		uint64_t elapsed = (stop.tv_usec + stop.tv_sec * 1000000);
		elapsed -= (start.tv_usec + start.tv_sec * 1000000);
		std::cout << elapsed << " us" << std::endl;
		microseconds += elapsed;
		if (sleep_us > 0) {
			usleep(sleep_us);
		}
	}
	std::cout << "Avg: " << microseconds / count << " us" << std::endl;
	return 0;
}
