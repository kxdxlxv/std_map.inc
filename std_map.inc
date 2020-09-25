/*
** The MIT License (MIT)
**
** Copyright (c) 2020 kxdxlxv
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
** OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
**
*/

const   MAP_MAX_KEYS      = 200; // change by your needs
static  STDMAP_HAS_ERROR  =   0; // don't change

enum STD_MAP
{
  bool: _stdmap_exists[MAP_MAX_KEYS],
  _stdmap_key[MAP_MAX_KEYS],
  _:_stdmap_value[MAP_MAX_KEYS]
}

static crc32(const string[], len)
{
  new crc = -1, pos = 0;

  while (len--) {
    crc = crc ^ string[pos++];

    // should be faster than 'for' cycle
    if (crc & 1) { crc = (crc >> 1) ^ 0xedb88320; } else { crc = (crc >> 1); }
    if (crc & 1) { crc = (crc >> 1) ^ 0xedb88320; } else { crc = (crc >> 1); }
    if (crc & 1) { crc = (crc >> 1) ^ 0xedb88320; } else { crc = (crc >> 1); }
    if (crc & 1) { crc = (crc >> 1) ^ 0xedb88320; } else { crc = (crc >> 1); }
    if (crc & 1) { crc = (crc >> 1) ^ 0xedb88320; } else { crc = (crc >> 1); }
    if (crc & 1) { crc = (crc >> 1) ^ 0xedb88320; } else { crc = (crc >> 1); }
    if (crc & 1) { crc = (crc >> 1) ^ 0xedb88320; } else { crc = (crc >> 1); }
    if (crc & 1) { crc = (crc >> 1) ^ 0xedb88320; } else { crc = (crc >> 1); }
  }

  return crc ^ 0xFFFFFFFF;
}

stock map_clear(map[STD_MAP])
{
  for (new i = 0; i < MAP_MAX_KEYS; i++) {
    map[_stdmap_exists]{i} = false;
  }

  STDMAP_HAS_ERROR = 0;

  return 1;
}

stock map_clear_error()
{
  STDMAP_HAS_ERROR = 0;
  return 1;
}

stock map_error()
{
  // so simple
  return STDMAP_HAS_ERROR;
}

stock map_exists(const map[STD_MAP], const name[])
{
  new crc = crc32(name, strlen(name));

  STDMAP_HAS_ERROR = 0;

  for (new i = 0; i < MAP_MAX_KEYS; i++) {
    if (map[_stdmap_exists][i] && map[_stdmap_key] == crc) {
      return 1;
    }
  }

  return 0;
}

stock map_get(const map[STD_MAP], const name[])
{
  new crc = crc32(name, strlen(name));

  for (new i = 0; i < MAP_MAX_KEYS; i++) {
    if (map[_stdmap_exists][i] && map[_stdmap_key][i] == crc) {
      STDMAP_HAS_ERROR = 0;
      return map[_stdmap_value][i];
    }
  }

  STDMAP_HAS_ERROR = 1;

  return -1;
}

stock Float: map_get_float(const map[STD_MAP], const name[])
{
  new crc = crc32(name, strlen(name));

  for (new i = 0; i < MAP_MAX_KEYS; i++) {
    if (map[_stdmap_exists][i] && map[_stdmap_key][i] == crc) {
      STDMAP_HAS_ERROR = 0;
      return Float:map[_stdmap_value][i];
    }
  }

  STDMAP_HAS_ERROR = 1;

  return -1;
}

stock map_remove(map[STD_MAP], const name[])
{
  new crc = crc32(name, strlen(name));

  STDMAP_HAS_ERROR = 0;

  for (new i = 0; i < MAP_MAX_KEYS; i++) {
    if (map[_stdmap_exists][i] && map[_stdmap_key] == crc) {
      map[_stdmap_exists][i] = false;
      return 1;
    }
  }

  return 0;
}

stock map_set(map[STD_MAP], const name[], value)
{
  new crc = crc32(name, strlen(name));

  STDMAP_HAS_ERROR = 0;

  for (new i = 0; i < MAP_MAX_KEYS; i++) {
    if (!map[_stdmap_exists][i]) {
      map[_stdmap_exists][i] = true;
      map[_stdmap_key][i] = crc;
      map[_stdmap_value][i] = _:value;
      return 1;
    }

    else if (map[_stdmap_key] == crc) {
      map[_stdmap_key][i] = crc;
      map[_stdmap_value][i] = _:value;
      return 2;
    }
  }

  return 0;
}

stock map_set_float(map[STD_MAP], const name[], Float: value)
{
  new crc = crc32(name, strlen(name));

  STDMAP_HAS_ERROR = 0;

  for (new i = 0; i < MAP_MAX_KEYS; i++) {
    if (!map[_stdmap_exists][i]) {
      map[_stdmap_exists][i] = true;
      map[_stdmap_key][i] = crc;
      map[_stdmap_value][i] = _:value;
      return 1;
    }

    else if (map[_stdmap_key] == crc) {
      map[_stdmap_key][i] = crc;
      map[_stdmap_value][i] = _:value;
      return 2;
    }
  }

  return 0;
}
