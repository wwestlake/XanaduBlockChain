#ifndef __BLOCK_H
#define __BLOCK_H

/*************************************************************************
    Xanadu Block Chain
    Copyright (C) 2018  W. Westlake wwestlake@lagdaemon.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
**************************************************************************/

#include <string>
#include <boost/shared_ptr.hpp>
#include "UTCDateTime.h"

class UTCDateTime;


/** The Block class represents a single block in the block chain.
 *
 *  The completed block chain contains a list of these blocks with
 *  the payload and hashes.  The payload must be serializable to string format
 *  for storage, transmission, and hashing.
 *
 */
template <typename Tpayload>
class Block
{
	shared_ptr<Block<Tpayload>> previousBlock;		//!< The previous block in the chain, null if this is the genesis block.
	shared_ptr<Block<Tpayload>> nextBlock;			//!< The next block in the chain, null if this is the last block.
	long blockId;						//!< The unique identifier of this block in the chain.
	Tpayload payload; 					//!< The payload of this block represents the information that is chained.
	UTCDateTime date_time_stamp;				//!< The data time stamp when this was created.  Should always be recorded in UTC (coordinated universal time)
	long nonce;						//!< Used to provide proof of work on block chains.
	std::string previousHash; 				//!< The hash of the previous block in this chain.
	std::string hash;					//!< The hash of a string representation of the blockId, payload, date_time_stamp, nonce, and previousHash concatenated together.
	
public:
	Block(Tpayload payload, shared_ptr<Block<Tpayload>> lastBlock)
	{
		this->payload = payload;
		this->previousHash = lastBlock->previousHash;
		this->blockId = getNextId();
		this->date_time_stamp = getUTCDateTime();
		this->nonce = 0;
		this->hash = hashBlock();
	}
	
	shared_ptr<Block<Tpayload>> getLastBlock()		//!< Gets the last block in the chain
	{
		auto current = shared_ptr<Block<Tpayload>>(this);
		while (current->getNextBlock() != nullptr)
			current = current->getNextBlock();
		return current;
	}
	shared_ptr<Block<Tpayload>> getGenesisBlock()  		//!< Gets the first block (genesis block) in the chain
	{
		auto current = shared_ptr<Block<Tpayload>>(this);
		while (current->getPrevBlock() != nullptr)
			current = current->getNextBlock();
		return shared_ptr<Blocl<Tpayload>>(current);
	}
	
	shared_ptr<Block<Tpayload>> getNextBlock()		//!< Gets the next block (genesis block) in the chain
	{
		return shared_ptr<Block<Tpayload>>(nextBlock);
	}
	
	shared_ptr<Block<Tpayload>> getPrevBlock()		//!< Gets the previous block (genesis block) in the chain
	{
		return shared_ptr<Blocl<Tpayload>>(precBlock);
	}
	
	long getNextId()					//!< Gets the next ID value for this chain
	{
		return getLastBlock()->blockId + 1;
	}
	
	hashBlock() = 0;						//!< Sets the hash values for this block, throws an exception if the block is already hashed and part of the chain
	verifyBlock() = 0;						//!< Verifies the hashes of this blocl
	verifyNonceSolution() = 0;					//!< Verifies that the nonce setting on this block meets the criteria
	shared_ptr<Block<Tpayload>> solveNonce(long newNonce) = 0; 	//!< Performs the nonce calculation for a specified nonce value, can only be called on new blocks
	UTCDateTime getUTCDateTime() = 0;				//!< Gets the current time in UTC. 	
};




#endif
