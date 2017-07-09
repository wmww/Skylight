#include "skylight_macro.h"

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
