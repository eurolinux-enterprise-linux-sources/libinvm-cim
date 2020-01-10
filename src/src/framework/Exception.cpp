/*
 * Copyright (c) 2015 2016, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of Intel Corporation nor the names of its contributors
 *     may be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * This file contains the implementation of the base NvmException class for the
 * Intel WBEM library.
 */


#include <logger/logging.h>
#include "Exception.h"

/*
 * Constructor for WBEM library exception base class
 */
wbem::framework::Exception::Exception()
{
	m_Message = EXCEPTION_UNKNOWN_MSG.c_str();
}

/*
 * Constructor for WBEM library exception base class
 */
wbem::framework::Exception::Exception(const std::string &msg)
	: m_Message(msg)
{
	if (m_Message.empty())
	{
		m_Message = EXCEPTION_UNKNOWN_MSG;
	}
	logDebugMessage();
}

/*
 * Log a debug message indicating the exception occurred
 */
void wbem::framework::Exception::logDebugMessage()
{
	COMMON_LOG_ERROR_F("Exception: %s", m_Message.c_str());
}

/*
 * Destructor
 */
wbem::framework::Exception::~Exception() throw ()
{
}

/*
 * Retrieve the message
 */
const char* wbem::framework::Exception::what() const throw ()
{
	return m_Message.c_str();
}
