#include "skylight_macro.h"
#include <string.h>

null_t null;

func _str(args data, size) {
	var abc = data;
	return tuple(
		_data,		abc,
		_byte_size,	0
		);
}

construct str() {
	return _str(null_raw_ptr('_'), 0);
}

construct str(args chr_ptr) {
	var len = strlen(chr_ptr);
	var data = malloc(len);
	memcpy(data, chr_ptr, len);
	return _str((char*)data, (int)len);
}

/*
operator (left: str) == (right: str)
{
	
}

bool operator==(get_type(str()))
*/

