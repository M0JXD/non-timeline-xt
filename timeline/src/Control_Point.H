
/*******************************************************************************/
/* Copyright (C) 2008-2021 Jonathan Moore Liles (as "Non-Timeline")            */
/* Copyright (C) 2023- Stazed                                                  */
/*                                                                             */
/* This file is part of Non-Timeline-XT                                        */
/*                                                                             */
/*                                                                             */
/* This program is free software; you can redistribute it and/or modify it     */
/* under the terms of the GNU General Public License as published by the       */
/* Free Software Foundation; either version 2 of the License, or (at your      */
/* option) any later version.                                                  */
/*                                                                             */
/* This program is distributed in the hope that it will be useful, but WITHOUT */
/* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       */
/* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for   */
/* more details.                                                               */
/*                                                                             */
/* You should have received a copy of the GNU General Public License along     */
/* with This program; see the file COPYING.  If not,write to the Free Software */
/* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
/*******************************************************************************/


#pragma once

#include "Sequence_Point.H"

class Control_Point : public Sequence_Point
{
    float _y;

protected:

    Control_Point ( )
    {
        _y = 0.0f;
        _box_color = FL_WHITE;
    }

    virtual void get ( Log_Entry &e ) const override;
    virtual void set ( Log_Entry &e ) override;

    Control_Point ( const Control_Point &rhs );

public:


    /* for loggable */
    LOG_CREATE_FUNC( Control_Point );
    SEQUENCE_WIDGET_CLONE_FUNC( Control_Point );

    Control_Point ( Sequence *t, nframes_t when, float y );

    ~Control_Point ( )
    {
        log_destroy();
    }

    float control ( void ) const
    {
        return _y;
    }
    void control ( float v )
    {
        _y = v;
    }
    /* only for playback thread */
    nframes_t when ( void ) const
    {
        return _range.start;
    }

    long abs_w ( void ) const override
    {
        return 8;
    }

    int y ( void ) const override
    {
        return parent()->y() + ((float)parent()->h() * _y);
    }
    int h ( void ) const override
    {
        return 8;
    }

    virtual void draw_box ( void ) override;
    virtual int handle ( int m ) override;

};
