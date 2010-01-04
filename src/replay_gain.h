/*
 * Copyright (C) 2003-2010 The Music Player Daemon Project
 * http://www.musicpd.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
/*
 * (c)2004 replayGain code by AliasMrJones
 */

#ifndef MPD_REPLAY_GAIN_H
#define MPD_REPLAY_GAIN_H

#include <stdbool.h>

enum replay_gain_mode {
	REPLAY_GAIN_OFF = -1,
	REPLAY_GAIN_ALBUM,
	REPLAY_GAIN_TRACK,
};

extern enum replay_gain_mode replay_gain_mode;
extern float replay_gain_preamp;
extern float replay_gain_missing_preamp;

struct replay_gain_tuple {
	float gain;
	float peak;
};

struct replay_gain_info {
	struct replay_gain_tuple tuples[2];
};

struct replay_gain_info *
replay_gain_info_new(void);

/**
 * Duplicate a #replay_gain_info object.
 */
struct replay_gain_info *
replay_gain_info_dup(const struct replay_gain_info *src);

void replay_gain_info_free(struct replay_gain_info *info);

void replay_gain_global_init(void);

/**
 * Returns the current replay gain mode as a machine-readable string.
 */
const char *
replay_gain_get_mode_string(void);

/**
 * Sets the replay gain mode, parsed from a string.
 *
 * @return true on success, false if the string could not be parsed
 */
bool
replay_gain_set_mode_string(const char *p);

#endif
