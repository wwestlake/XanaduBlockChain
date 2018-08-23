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
#include "boost/date_time/gregorian/gregorian.hpp"

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
	Block<Tpayload> *previousBlock;		//!< The previous block in the chain, null if this is the genesis block.
	Block<Tpayload> *nextBlock;		//!< The next block in the chain, null if this is the last block.
	long long blockId;			//!< The unique identifier of this block in the chain.
	Tpayload payload; 			//!< The payload of this block represents the information that is chained.
	boost::date date_time_stamp;		//!< The data time stamp when this was created.  Should always be recorded in UTC (coordinated universal time)
	long nonce;				//!< Used to provide proof of work on block chains.
	std::string previousHash; 		//!< The hash of the previous block in this chain.
	std::string hash;			//!< The hash of a string representation of the blockId, payload, date_time_stamp, nonce, and previousHash concatenated together.
	
public:
	Block();
	

};




#endif
