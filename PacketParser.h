//	MIT License
//
//  Copyright (c) 2018 Michael J Simms. All rights reserved.
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files (the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in all
//	copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//	SOFTWARE.

#pragma once

#include <vector>
#include "NetworkDefinitions.h"

namespace PacketParser
{
	typedef enum HeaderType {
		HEADER_ETHER = 0,
		HEADER_IPV4,
		HEADER_IPV6,
		HEADER_TCP,
		HEADER_UDP,
		HEADER_ARP,
		HEADER_ICMPV4,
		HEADER_ICMPV6,
		HEADER_DNS,
		HEADER_MDNS,
		HEADER_HTTP,
		HEADER_HTTPS
	} HeaderType;

	typedef std::pair<HeaderType, const uint8_t*> HeaderRef; // The second item in the pair is a pointer to the start of the header.
	typedef std::vector<HeaderRef> HeaderList;

	void Parse(const uint8_t* data, size_t dataLen, HeaderList& headers);
};
