/*
   Copyright 2013-2014 EditShare, 2013-2015 Skytechnology sp. z o.o.

   This file is part of LizardFS.

   LizardFS is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, version 3.

   LizardFS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with LizardFS. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "common/platform.h"

#include <array>

#include "common/access_control_list.h"
#include "common/acl_type.h"
#include "common/moosefs_string.h"
#include "common/serialization_macros.h"
#include "protocol/lock_info.h"
#include "protocol/MFSCommunication.h"
#include "protocol/packet.h"
#include "protocol/quota.h"

LIZARDFS_DEFINE_PACKET_SERIALIZATION(cltoma, fuseMknod, LIZ_CLTOMA_FUSE_MKNOD, 0,
		uint32_t, messageId,
		uint32_t, inode,
		MooseFsString<uint8_t>, name,
		uint8_t, nodeType,
		uint16_t, mode,
		uint16_t, umask,
		uint32_t, uid,
		uint32_t, gid,
		uint32_t, rdev)

LIZARDFS_DEFINE_PACKET_SERIALIZATION(cltoma, fuseMkdir, LIZ_CLTOMA_FUSE_MKDIR, 0,
		uint32_t, messageId,
		uint32_t, inode,
		MooseFsString<uint8_t>, name,
		uint16_t, mode,
		uint16_t, umask,
		uint32_t, uid,
		uint32_t, gid,
		bool, copySgid)

LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, fuseDeleteAcl, LIZ_CLTOMA_FUSE_DELETE_ACL, 0,
		uint32_t, messageId,
		uint32_t, inode,
		uint32_t, uid,
		uint32_t, gid,
		AclType, type)

LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, fuseGetAcl, LIZ_CLTOMA_FUSE_GET_ACL, 0,
		uint32_t, messageId,
		uint32_t, inode,
		uint32_t, uid,
		uint32_t, gid,
		AclType, type)

LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, fuseSetAcl, LIZ_CLTOMA_FUSE_SET_ACL, 0,
		uint32_t, messageId,
		uint32_t, inode,
		uint32_t, uid,
		uint32_t, gid,
		AclType, type,
		AccessControlList, acl)

LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, iolimit, LIZ_CLTOMA_IOLIMIT, 0,
		uint32_t, msgid,
		uint32_t, configVersion,
		std::string, group,
		uint64_t, requestedBytes)

// LIZ_CLTOMA_FUSE_SET_QUOTA
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, fuseSetQuota, LIZ_CLTOMA_FUSE_SET_QUOTA, 0,
		uint32_t, messageId,
		uint32_t, uid,
		uint32_t, gid,
		std::vector<QuotaEntry>, quotaEntries)

// LIZ_CLTOMA_FUSE_DELETE_QUOTA
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, fuseDeleteQuota, LIZ_CLTOMA_FUSE_DELETE_QUOTA, 0,
		uint32_t, messageId,
		uint32_t, uid,
		uint32_t, gid,
		std::vector<QuotaEntryKey>, quotaEntriesKeys)

// LIZ_CLTOMA_FUSE_GET_QUOTA
LIZARDFS_DEFINE_PACKET_VERSION(cltoma, fuseGetQuota, kAllLimits, 0)
LIZARDFS_DEFINE_PACKET_VERSION(cltoma, fuseGetQuota, kSelectedLimits, 1)
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, fuseGetQuota, LIZ_CLTOMA_FUSE_GET_QUOTA, kAllLimits,
		uint32_t, messageId,
		uint32_t, uid,
		uint32_t, gid)

LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, fuseGetQuota, LIZ_CLTOMA_FUSE_GET_QUOTA, kSelectedLimits,
		uint32_t, messageId,
		uint32_t, uid,
		uint32_t, gid,
		std::vector<QuotaOwner>, owners)

// LIZ_CLTOMA_IOLIMITS_STATUS
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, iolimitsStatus, LIZ_CLTOMA_IOLIMITS_STATUS, 0,
		uint32_t, messageId)

// LIZ_CLTOMA_METADATASERVER_STATUS
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, metadataserverStatus, LIZ_CLTOMA_METADATASERVER_STATUS, 0,
		uint32_t, messageId)

// LIZ_CLTOMA_METADATASERVERS_LIST
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, metadataserversList, LIZ_CLTOMA_METADATASERVERS_LIST, 0)

// LIZ_CLTOMA_FUSE_GETGOAL
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, fuseGetGoal, LIZ_CLTOMA_FUSE_GETGOAL, 0,
		uint32_t, messageId,
		uint32_t, inode,
		uint8_t, gmode)

// LIZ_CLTOMA_FUSE_SETGOAL
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, fuseSetGoal, LIZ_CLTOMA_FUSE_SETGOAL, 0,
		uint32_t, messageId,
		uint32_t, inode,
		uint32_t, uid,
		std::string, goalName,
		uint8_t, smode)

// LIZ_CLTOMA_LIST_GOALS
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, listGoals, LIZ_CLTOMA_LIST_GOALS, 0,
		bool, dummy)

// LIZ_CLTOMA_CHUNKS_HEALTH
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, chunksHealth, LIZ_CLTOMA_CHUNKS_HEALTH, 0,
		bool, regularChunksOnly)

// LIZ_CLTOMA_CSERV_LIST
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, cservList, LIZ_CLTOMA_CSERV_LIST, 0,
		bool, dummy)

// LIZ_CLTOMA_CHUNK_INFO
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, chunkInfo, LIZ_CLTOMA_CHUNK_INFO, 0,
		uint32_t, messageId,
		uint32_t, inode,
		uint32_t, chunkIndex)

// LIZ_CLTOMA_HOSTNAME
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, hostname, LIZ_CLTOMA_HOSTNAME, 0)

// LIZ_CLTOMA_ADMIN_REGISTER
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, adminRegister, LIZ_CLTOMA_ADMIN_REGISTER_CHALLENGE, 0)

// LIZ_CLTOMA_ADMIN_REGISTER_RESPONSE
typedef std::array<uint8_t, 16> LizCltomaAdminRegisterResponseData;
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, adminRegisterResponse, LIZ_CLTOMA_ADMIN_REGISTER_RESPONSE, 0,
		LizCltomaAdminRegisterResponseData, data)

// LIZ_CLTOMA_ADMIN_BECOME_MASTER
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, adminBecomeMaster, LIZ_CLTOMA_ADMIN_BECOME_MASTER, 0)

// LIZ_CLTOMA_ADMIN_STOP_WITHOUT_METADATA_DUMP
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, adminStopWithoutMetadataDump, LIZ_CLTOMA_ADMIN_STOP_WITHOUT_METADATA_DUMP, 0)

// LIZ_CLTOMA_ADMIN_RELOAD
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, adminReload, LIZ_CLTOMA_ADMIN_RELOAD, 0)

// LIZ_CLTOMA_ADMIN_SAVE_METADATA
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, adminSaveMetadata, LIZ_CLTOMA_ADMIN_SAVE_METADATA, 0,
		bool, asynchronous)

// LIZ_CLTOMA_ADMIN_RECALCULATE_METADATA_CHECKSUM
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, adminRecalculateMetadataChecksum, LIZ_CLTOMA_ADMIN_RECALCULATE_METADATA_CHECKSUM, 0,
		bool, asynchronous)

// LIZ_CLTOMA_TAPE_INFO
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, tapeInfo, LIZ_CLTOMA_TAPE_INFO, 0,
		uint32_t, messageId,
		uint32_t, inode)

// LIZ_CLTOMA_LIST_TAPESERVERS
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, listTapeservers, LIZ_CLTOMA_LIST_TAPESERVERS, 0)

LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, fuseTruncate, LIZ_CLTOMA_FUSE_TRUNCATE, 0,
		uint32_t, messageId,
		uint32_t, inode,
		bool, isOpened,
		uint32_t, uid,
		uint32_t, gid,
		uint64_t, length)

LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, fuseTruncateEnd, LIZ_CLTOMA_FUSE_TRUNCATE_END, 0,
		uint32_t, messageId,
		uint32_t, inode,
		uint32_t, uid,
		uint32_t, gid,
		uint64_t, length,
		uint32_t, lockid)

// FILE LOCKS
LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, fuseFlock, LIZ_CLTOMA_FUSE_FLOCK, 0,
		uint32_t, messageId,
		uint32_t, inode,
		uint64_t, owner,
		uint32_t, requestId,
		uint16_t, operation)

LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, fuseFlock, LIZ_CLTOMA_FUSE_FLOCK_INTERRUPT, 0,
		uint32_t, messageId,
		lzfs_locks::InterruptData, interruptData)

LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, fuseGetlk, LIZ_CLTOMA_FUSE_GETLK, 0,
		uint32_t, messageId,
		uint32_t, inode,
		uint64_t, owner,
		lzfs_locks::FlockWrapper, lock)

LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, fuseSetlk, LIZ_CLTOMA_FUSE_SETLK, 0,
		uint32_t, messageId,
		uint32_t, inode,
		uint64_t, owner,
		uint32_t, requestId,
		lzfs_locks::FlockWrapper, lock)

LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, fuseSetlk, LIZ_CLTOMA_FUSE_SETLK_INTERRUPT, 0,
		uint32_t, messageId,
		lzfs_locks::InterruptData, interruptData)

LIZARDFS_DEFINE_PACKET_VERSION(cltoma, manageLocksList, kAll, 0)
LIZARDFS_DEFINE_PACKET_VERSION(cltoma, manageLocksList, kInode, 1)

#define LIZ_CLTOMA_MANAGE_LOCKS_LIST_LIMIT 1024

LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, manageLocksList, LIZ_CLTOMA_MANAGE_LOCKS_LIST, kAll,
		lzfs_locks::Type, type,
		bool, pending,
		uint64_t, start,
		uint64_t, max)

LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, manageLocksList, LIZ_CLTOMA_MANAGE_LOCKS_LIST, kInode,
		uint32_t, inode,
		lzfs_locks::Type, type,
		bool, pending,
		uint64_t, start,
		uint64_t, max)

LIZARDFS_DEFINE_PACKET_VERSION(cltoma, manageLocksUnlock, kSingle, 0)
LIZARDFS_DEFINE_PACKET_VERSION(cltoma, manageLocksUnlock, kInode, 1)

LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, manageLocksUnlock, LIZ_CLTOMA_MANAGE_LOCKS_UNLOCK, kSingle,
		lzfs_locks::Type, type,
		uint32_t, inode,
		uint32_t, sessionid,
		uint64_t, owner,
		uint64_t, start,
		uint64_t, end)

LIZARDFS_DEFINE_PACKET_SERIALIZATION(
		cltoma, manageLocksUnlock, LIZ_CLTOMA_MANAGE_LOCKS_UNLOCK, kInode,
		lzfs_locks::Type, type,
		uint32_t, inode)

namespace cltoma {

namespace fuseReadChunk {

inline void serialize(std::vector<uint8_t>& destination,
		uint32_t messageId, uint32_t inode, uint32_t chunkIndex) {
	serializePacket(destination, LIZ_CLTOMA_FUSE_READ_CHUNK, 0, messageId, inode,
			chunkIndex);
}

inline void deserialize(const std::vector<uint8_t>& source,
		uint32_t& messageId, uint32_t& inode, uint32_t& chunkIndex) {
	verifyPacketVersionNoHeader(source, 0);
	deserializeAllPacketDataNoHeader(source, messageId, inode, chunkIndex);
}

} // namespace fuseReadChunk

namespace fuseWriteChunk {

inline void serialize(std::vector<uint8_t>& destination,
		uint32_t messageId, uint32_t inode, uint32_t chunkIndex, uint32_t lockId) {
	serializePacket(destination, LIZ_CLTOMA_FUSE_WRITE_CHUNK, 0,
			messageId, inode, chunkIndex, lockId);
}

inline void deserialize(const std::vector<uint8_t>& source,
		uint32_t& messageId, uint32_t& inode, uint32_t& chunkIndex, uint32_t& lockId) {
	verifyPacketVersionNoHeader(source, 0);
	deserializeAllPacketDataNoHeader(source, messageId, inode, chunkIndex, lockId);
}

} // namespace fuseWriteChunk

namespace fuseWriteChunkEnd {

inline void serialize(std::vector<uint8_t>& destination,
		uint32_t messageId, uint64_t chunkId, uint32_t lockId,
		uint32_t inode, uint64_t fileLength) {
	serializePacket(destination, LIZ_CLTOMA_FUSE_WRITE_CHUNK_END, 0,
			messageId, chunkId, lockId, inode, fileLength);
}


inline void deserialize(const std::vector<uint8_t>& source,
		uint32_t& messageId, uint64_t& chunkId, uint32_t& lockId,
		uint32_t& inode, uint64_t& fileLength) {
	verifyPacketVersionNoHeader(source, 0);
	deserializeAllPacketDataNoHeader(source, messageId, chunkId, lockId, inode, fileLength);
}

} // namespace fuseWriteChunkEnd

} // namespace cltoma
