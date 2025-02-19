
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

#include "Sequence_Widget.H"

class Sequence_Point : public Sequence_Widget
{
    /* not permitted  */
    Sequence_Point & operator= ( const Sequence_Point &rhs );

protected:

    void get ( Log_Entry &e ) const override;
    void set ( Log_Entry &e ) override;

    virtual void draw_box ( void ) override;
    virtual void draw ( void ) override;

    Sequence_Point ( const Sequence_Point &rhs );
    Sequence_Point ( );
    virtual ~Sequence_Point ( );

public:

    Fl_Align align ( void ) const override
    {
        return FL_ALIGN_RIGHT;
    }
    virtual long abs_w ( void ) const override
    {
        return 8;
    }

//    virtual int abs_x ( void ) const { return Sequence_Widget::abs_x() - ( abs_w() >> 1 ); }
//    virtual int x ( void ) const { return Sequence_Widget::line_x() - ( abs_w() >> 1 ); }

    virtual int x ( void ) const override
    {
        return line_x();
    }

    nframes_t length ( void ) const override
    {
        return timeline->x_to_ts( abs_w() );
    }

};
