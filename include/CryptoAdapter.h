#ifndef __CRYPTO_ADAPTER_H
#define __CRYPTO_ADAPTER_H


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
#include "KeyPair.h"
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <openssl/x509.h>
#include <memory>


/** The CryptoAdapter is an abstract class where implementations provide cryptographic services.
 *
 *
 */
class CryptoAdapter {

public:

	std::string CreateHash(std::string valueToHash) = 0;
	bool VerifyHash(std::string hash, std::string valueToHash) = 0;
	KeyPair GenerateKeys(std::string )



};



#endif
