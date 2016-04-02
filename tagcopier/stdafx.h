// stdafx.h: Includedatei für Standardsystem-Includedateien
// oder häufig verwendete projektspezifische Includedateien,
// die nur in unregelmäßigen Abständen geändert werden.
//

#pragma once

#include "targetver.h"

#include <iostream>
#include <iomanip>

#include <stdio.h>
#include <tchar.h>

// TODO: Hier auf zusätzliche Header, die das Programm erfordert, verweisen.

#include "fileref.h"
#include "tag.h"
#include "toolkit/tpropertymap.h"

#include "mpeg/mpegfile.h"
#include "mpeg/id3v2/frames/attachedpictureframe.h"
#include "mpeg/id3v2/id3v2tag.h"
#include "mp4/mp4file.h"
#include "mp4/mp4tag.h"
#include "mp4/mp4coverart.h"
#include "flac/flacpicture.h"
