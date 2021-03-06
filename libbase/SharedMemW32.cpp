// SharedMem implementation for w32
//
//   Copyright (C) 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012
//   Free Software Foundation, Inc
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#ifdef HAVE_CONFIG_H
# include "gnashconfig.h"
#endif

#include "SharedMem.h"

#include <windows.h>
#include <process.h>
#include <io.h>

#include "log.h"
#include "rc.h"

namespace {
    gnash::RcInitFile& rcfile = gnash::RcInitFile::getDefaultInstance();
}

namespace gnash {

SharedMem::SharedMem(size_t size)
    :
    _addr(0),
    _size(size),
    _semid(0),
    _shmid(0),
    _shmkey(0)
{
    log_unimpl("%s on w32", __FUNCTION__);
}

SharedMem::~SharedMem()
{
    log_unimpl("%s on w32", __FUNCTION__);
}

bool
SharedMem::lock() const
{
    log_unimpl("%s on w32", __FUNCTION__);
    return false;
}

bool
SharedMem::unlock() const
{
    log_unimpl("%s on w32", __FUNCTION__);
    return false;
}

bool
SharedMem::attach()
{
    log_unimpl("%s on w32", __FUNCTION__);
    return false;
}

} // end of gnash namespace

// Local Variables:
// mode: C++
// indent-tabs-mode: nil
// End:
