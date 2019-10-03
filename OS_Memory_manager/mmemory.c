#include "mmemory.h"
#include "segment_table.h"
#include "adress_spaces.h"

#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 

int _malloc (VA* ptr, size_t szBlock)
{
	if (szBlock == 0 || ptr == NULL) return _WRONG_PARAMS;
	
	int return_code = 0;
	return_code = _request_free_space(szBlock);
	if (return_code != _SUCCESS) return return_code;

	return_code = _init_first_free_adress(szBlock);
	if (return_code != _SUCCESS) return return_code;

	return_code = _allocate_segment(szBlock);
	if (return_code != _SUCCESS) return return_code;

	*ptr = *_first_free_va;
	segment* new_segment = (segment*)malloc(sizeof(segment));
	if (new_segment == NULL) return _UNKNOWN_ERR;

	new_segment->size			= szBlock;
	new_segment->starting_va	= *ptr;
	new_segment->starting_pa	= *_first_free_pa;

	return_code = _register_segment(new_segment);
	if (return_code != _SUCCESS) return return_code;

	_renew_first_free_adress(szBlock);

	return _SUCCESS;
}

int _free (VA ptr)
{
	if (ptr == NULL)
	{
		return _WRONG_PARAMS;
	}

	segment* found_segment = _find_segment(ptr);
	if (found_segment == NULL)
	{
		return _WRONG_PARAMS;
	}

	// ���������?
	uint segment_starting_adress_offset = _validate_va(found_segment->starting_va);
	if (segment_starting_adress_offset == _FORBIDDEN_ADRESS_OFFSET)
	{
		return _UNKNOWN_ERR;
	}

	uint adress_offset = 0;
	while (adress_offset < found_segment->size)
	{
		*(_vas + segment_starting_adress_offset + adress_offset) = NULL;
		adress_offset++;
	}
	//ptr = NULL;

	_unload_from_mem(found_segment);
	_remove_record_from_segment_table(found_segment);

	return _SUCCESS;
}

int _read(VA ptr, void* pBuffer, size_t szBuffer) 
{

	return _SUCCESS;
}

int _write(VA ptr, void* pBuffer, size_t szBuffer) 
{

	return _SUCCESS;
}

int _init(int n, int szPage) 
{
	int init_pas_return_code = _init_pas(n * szPage);
	if (init_pas_return_code != _SUCCESS)
	{
		return init_pas_return_code;
	}

	int init_vas_return_code = _init_vas(n * szPage);
	if (init_vas_return_code != _SUCCESS)
	{
		return init_vas_return_code;
	}

	int init_st_return_code = _init_segment_table();
	if (init_st_return_code != _SUCCESS) {
		return init_st_return_code;
	}

	return _SUCCESS;
}
