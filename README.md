# STD Map include

Simple hash map implemented in Pawn, with CRC32 as hash function.

## Usage

```pawn
new map[STD_MAP];
map_clear(map); // im not sure is arrays zero filled at initialization or not

map_set(map, "a", 10);
map_set(map, "b", 10);

new a = map_get(map, "a");

if (map_error()) {
  // ...
}

new b = map_get(map, "b");

if (map_error()) {
   // ...
}

printf("%d + %d = %d", a, b, a + b);

map_remove(map, "a");
map_remove(map, "b");

```

## API

**`stock map_clear(map[STD_MAP])`**

Clears the contents.

**Returns:** always 1

-----

**`stock map_clear_error()`**

Sets error code to 0.

**Returns:** always 1

-----

**`stock map_error()`**

Returns 1 if error was happened.

**Returns:** 0 if no error happened, else 1

-----

**`stock map_exists(const map[STD_MAP], const name[])`**

Checks if the map contains element with specific key.

**Returns:** ?

-----

**`stock map_get(const map[STD_MAP], const name[])`**

Finds element with specific key.

**Returns:** value, if not found -1

-----

**`stock Float: map_get_float(const map[STD_MAP], const name[])`**

Finds element with specific key.

**Returns:** float value, if not found -1

-----

**`stock map_remove(map[STD_MAP], const name[])`**

Removes an element from the map.

**Returns:** 1 if removed, else 0

-----

**`stock map_set(map[STD_MAP], const name[], value)`**

Inserts an element into the map.

**Returns:** 1 if created; 2 if updated; 0 if map is full

-----

**`stock map_set_float(map[STD_MAP], const name[], Float: value)`**

Inserts an element into the map.

**Returns:** 1 if created; 2 if updated; 0 if map is full

-----

## TODO

1. Support of strings & arrays; *\[ maybe \]*
1. Support of SHA256_PassHash; *\[ SAMP \]*
1. Rewrite to C++;
1. Correct implementation of CRC32;
1. Create tests;

## License

MIT
