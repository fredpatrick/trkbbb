/*
 * ============================================================================
 *                   The XyloComp Software License, Version 1.1
 * ============================================================================
 * 
 *    Copyright (C) 2016 XyloComp Inc. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modifica-
 * tion, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of  source code must  retain the above copyright  notice,
 *    this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * 3. The end-user documentation included with the redistribution, if any, must
 *    include  the following  acknowledgment:  "This product includes  software
 *    developed  by  XyloComp Inc.  (http://www.xylocomp.com/)." Alternately, 
 *    this  acknowledgment may  appear in the software itself,  if
 *    and wherever such third-party acknowledgments normally appear.
 * 
 * 4. The name "XyloComp" must not be used to endorse  or promote  products 
 *    derived  from this  software without  prior written permission. 
 *    For written permission, please contact fred.patrick@xylocomp.com.
 * 
 * 5. Products  derived from this software may not  be called "XyloComp", 
 *    nor may "XyloComp" appear  in their name,  without prior written 
 *    permission  of Fred Patrick
 * 
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS  FOR A PARTICULAR  PURPOSE ARE  DISCLAIMED.  IN NO  EVENT SHALL
 * XYLOCOMP INC. OR ITS CONTRIBUTORS  BE LIABLE FOR  ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL,  EXEMPLARY, OR CONSEQUENTIAL  DAMAGES (INCLU-
 * DING, BUT NOT LIMITED TO, PROCUREMENT  OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR  PROFITS; OR BUSINESS  INTERRUPTION)  HOWEVER CAUSED AND ON
 * ANY  THEORY OF LIABILITY,  WHETHER  IN CONTRACT,  STRICT LIABILITY,  OR TORT
 * (INCLUDING  NEGLIGENCE OR  OTHERWISE) ARISING IN  ANY WAY OUT OF THE  USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#include "drivers.h"
#include "blockdrivers.h"
#include "breakdrivers.h"
#include "switchdrivers.h"
#include "trackdrivers.h"
#include "eventdevice.h"

trk::Drivers* trk::Drivers::instance_ = 0;

trk::Drivers*
trk::Drivers::
instance()
{
    if ( !instance_ ) {
        instance_ = new Drivers();
    }
    return instance_;
}

trk::Drivers::
Drivers()
{
    block_drivers_ = new BlockDrivers();
    break_drivers_  = new BreakDrivers();
    switch_drivers_ = new SwitchDrivers();
    track_drivers_  = new TrackDrivers();
}

trk::Drivers::
~Drivers()
{
    delete block_drivers_;
    delete break_drivers_;
    delete switch_drivers_;
    delete track_drivers_;
}

void
trk::Drivers::
enable(EventDevice* efd)
{
    break_drivers_->enable_sensors(efd);
    block_drivers_->enable_sensors(efd);
    switch_drivers_->enable_sensors(efd);
    track_drivers_->enable_sensors(efd);
}

trk::BreakDrivers*
trk::Drivers::
break_drivers()
{
    return break_drivers_;
}

trk::BlockDrivers*
trk::Drivers::
block_drivers()
{
    return block_drivers_;
}

trk::SwitchDrivers*
trk::Drivers::
switch_drivers()
{
    return switch_drivers_;
}

trk::TrackDrivers*
trk::Drivers::
track_drivers()
{
    return track_drivers_;
}
