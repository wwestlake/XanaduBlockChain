#ifndef INCLUDE_SIGNATURE_H_
#define INCLUDE_SIGNATURE_H_

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
#include "CryptoAdapter.h"

template <typename Tconfig, typename Tpayload>
class Signature {
	Tpayload payload;
	std::string signature;

public:
	Signature(Tpayload payload, std::string signature)
	{
		this->payload = payload;
		this->signature = signature;
	}

	bool ValidateSignature(CryptoAdapter<Tconfig, Tpayload> crypto) = 0;


};




#endif /* INCLUDE_SIGNATURE_H_ */
