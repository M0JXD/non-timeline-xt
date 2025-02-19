
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

#include "Audio_File.H"

#include <sndfile.h>

class Audio_File_SF : public Audio_File
{
//    Audio_File_SF ( const char *filename )

    SNDFILE *_in;

    /* used to avoid unnecessary seeking--libsndfile isn't smart
     * enough to do this for us */
    volatile nframes_t _current_read;

    Audio_File_SF ( ) : _in(0), _current_read(0) { }

public:

    static const Audio_File::format_desc supported_formats[];

    static Audio_File_SF *from_file ( const char *filename );
    static Audio_File_SF *create ( const char *filename, nframes_t samplerate, int channels, const char *format );


    ~Audio_File_SF ( )
    {
        /* stupid C++ */
        Audio_File_SF::close();
    }

    bool open ( void ) override;
    void close ( void ) override;
    void seek ( nframes_t offset ) override;
    nframes_t read ( sample_t *buf, int channel, nframes_t len ) override;
    nframes_t read ( sample_t *buf, int channel,  nframes_t start, nframes_t len ) override;
    nframes_t write ( sample_t *buf, nframes_t nframes ) override;

};
