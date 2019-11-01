#include "mmemory.h"

/**
	v	- �����������
	va	- ����������� �����
	vas - ����������� �������� ������������
	
	p	- ����������
	pa	- ���������� �����
	pas - ���������� �������� ������������
	st	- ������� ���������
**/

#ifndef ADRESS_SPACES_H
#define ADRESS_SPACES_H

// ���������� ��� unsigned int (�� size_t!)
typedef unsigned int uint;

// ���, ����������� ������� ������
typedef struct
{
	VA		starting_va;
	VA		starting_pa;
	size_t	size;
}
segment;

// ����������� ������ ����������� ��������� ������������ (� ������)
#define _PAS_MIN_SIZE (\
	sizeof(segment_table) + sizeof(st_record) * _ST_MAX_RECORDS_COUNT \
	)
#define _PAS_MAX_SIZE 100 * 1024			// ������������ ������ ����������� ��������� ������������ (� ������)
#define _VAS_MAX_SIZE _PAS_MAX_SIZE		// ������������ ������ ������������ ��������� ������������ (� ������)
#define _FORBIDDEN_ADRESS_OFFSET -1		// ����� ��� ����������� ��������� �����������
#define _VAS_NAME "Virtual adress space"
#define _PAS_NAME "Physical adress space"

VA*		_pas;							// ���������� �������� ������������
VA*		_vas;							// ����������� �������� ������������

size_t	_pas_size;						// ������� ������ ����������� ��������� ������������
size_t	_vas_size;						// ������� ������ ������������ ��������� ������������

VA*		_first_free_pa;					// ������ ��������� ���������� ����� 
VA*		_first_free_va;					// ������ ��������� ����������� ����� 

VA*		_last_free_pa;					// ��������� ��������� ���������� ����� 
VA*		_last_free_va;					// ��������� ��������� ����������� ����� 

/**
	@func	_init_pas
	@brief	������������� ����������� ��������� ������������
**/
int		_init_pas (size_t size);

/**
	@func	_init_vas
	@brief	������������� ������������ ��������� ������������
**/
int		_init_vas (size_t size);

/**
	@func	_init_adress
	@brief	������������� ������, ������� �����
			�������� ��������� ������� ��������
**/
int		_init_adress (VA* adress, size_t content_size);

/**
	@func	_adress_abs_offset
	@brief	��������� ����������� �������� ������
**/
uint	_adress_abs_offset(VA* space, VA adress);

/**
	@func	_clear_space_region
	@brief	��������� ������� �� �������� �������
**/
void	_clear_space_region (VA* starting_adress, size_t size);

/**
	@func	_first_null_content_adress
	@brief	��������� ������ ������ ��������� ������
**/
VA*		_first_null_content_adress (
		VA* space,
		VA* starting_adress,
		VA* last_free_space_adress
);

/**
	@func	_nulled_space_region_size
	@brief	��������� ������� ������ �������
**/
size_t	_nulled_space_region_size(VA* space, VA* space_region);

/**
	@func	_request_space_region_access
	@brief	��������� ������� � ������� ������
**/
int		_request_space_region_access (VA va, VA* pa, size_t region_size);

/**
	@func	_request_free_space_region
	@brief	��������� ������ ������� ��������� �������
**/
VA*		_request_free_space_region (
		VA* space,
		VA* last_free_space_adress,
		size_t size
);

/**
	@func	_organize_space_for_segment_allocation
	@brief	����� ����� ��� �������������� ��������� ������������
**/
int		_organize_space_for_segment_allocation(
		VA* space,
		VA** first_free_space_adress,
		VA* last_free_space_adress,
		size_t segment_size
);

/**
	@func	_allocate_segment
	@brief	���������� �������� � �������� ������������
**/
int	_allocate_segment(VA* allocationg_adress, size_t size);

/**
	@func	_register_segment
	@brief	���������� ���������� � �������� �
			���������� �������
**/
int	_register_segment(segment* segment);

/**
	@func	_load_segment
	@brief	�������� �������� � ���������� �������� ������������
**/
int	_load_segment(segment* segment);

/**
	@func	_load_adjacent_segments
	@brief	�������� ������� ���������
**/
int _load_adjacent_segments(segment* central_segment);

/**
	@func	_unload_segment
	@brief	�������� �������� �� ����������� ��������� ������������
**/
void _unload_segment(segment* segment);

/**
	@func	_unload_random_segment
	@brief	�������� ���������� ��������
**/
void _unload_random_segment ();

/**
	@func	_unload_segments_to_free_space
	@brief	�������� ��������� ��� ������������ �����
**/
int _unload_segments_to_free_space (size_t space_region_size);

/**
	@func	_print_space
	@brief	����� ����������� ��������� ������������
**/
void _print_space (
	VA* space,
	size_t adress_offset_limit,
	const char* space_name
);

#endif // !ADRESS_SPACES_H
