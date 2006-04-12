// Filename: mutexSpinlockImpl.h
// Created by:  drose (11Apr06)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) 2001 - 2004, Disney Enterprises, Inc.  All rights reserved
//
// All use of this software is subject to the terms of the Panda 3d
// Software license.  You should have received a copy of this license
// along with this source code; you will also find a current copy of
// the license at http://etc.cmu.edu/panda3d/docs/license/ .
//
// To contact the maintainers of this program write to
// panda3d-general@lists.sourceforge.net .
//
////////////////////////////////////////////////////////////////////

#ifndef MUTEXSPINLOCKIMPL_H
#define MUTEXSPINLOCKIMPL_H

#include "dtoolbase.h"
#include "selectThreadImpl.h"

#ifdef MUTEX_SPINLOCK

#include "atomicAdjust.h"

////////////////////////////////////////////////////////////////////
//       Class : MutexSpinlockImpl
// Description : Uses Windows native calls to implement a mutex.
////////////////////////////////////////////////////////////////////
class EXPCL_DTOOL MutexSpinlockImpl {
public:
  INLINE MutexSpinlockImpl();
  INLINE ~MutexSpinlockImpl();

  INLINE void lock();
  INLINE bool try_lock();
  INLINE void release();

private:
  void do_lock();

  volatile PN_int32 _lock;
};

#include "mutexSpinlockImpl.I"

#endif  // MUTEX_SPINLOCK

#endif
