#include "mmemory.h"

/**
	v	- �����������
	va	- ����������� �����
	vas - ����������� �������� ������������
	
	p	- ����������
	pa	- ���������� �����
	pas - ���������� �������� ������������
	st	- ������� ���������
	mem	- ���������� ������
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
#define _PAS_MAX_SIZE 10 * 1024			// ������������ ������ ����������� ��������� ������������ (� ������)
#define _VAS_MAX_SIZE _PAS_MAX_SIZE		// ������������ ������ ������������ ��������� ������������ (� ������)
#define _FORBIDDEN_ADRESS_OFFSET -1		// ����� ��� ����������� ��������� �����������

VA*			_pas;						// ���������� �������� ������������
VA*			_vas;						// ����������� �������� ������������

size_t		_pas_size;					// ������� ������ ����������� ��������� ������������
size_t		_vas_size;					// ������� ������ ������������ ��������� ������������

VA*			_first_free_pa;				// ������ ��������� ���������� ����� 
VA*			_first_free_va;				// ������ ��������� ����������� ����� 

VA*			_last_free_pa;				// ��������� ��������� ���������� ����� 
VA*			_last_free_va;				// ��������� ��������� ����������� ����� 

int			_init_pas(size_t size);
int			_init_vas(size_t size);

void		_unload_segment (segment* segment);
void		_load_adjacent_segments_into_mem (segment* central_segment);


uint		_adress_abs_offset (VA* space, VA adress);
segment*	_find_segment (VA starting_va);


VA*	_defragment_space(VA* space, VA* last_free_space_adress);
void _clear_space_region(VA* starting_adress, size_t size);

/*
	@func	_shift_space_content_left
	@brief	����� ����������� ������� ������������ �����
*/
void _shift_space_content_left	(
	VA*	starting_adress, 
	VA*	last_free_space_adress, 
	uint offset
	);

VA*	_request_free_space_region	(
	VA* space,
	VA*	last_free_space_adress,
	size_t size
	);

size_t _nulled_space_region_size (VA* space, VA* space_region);
void _print_space(VA* space, size_t adress_offset_limit, const char* space_name);


/**
	@func	_organize_space_for_segment_allocation
	@brief	����� ����� ��� �������������� ���. ������������
**/
int	_organize_space_for_segment_allocation(
	VA* space,
	VA** first_free_space_adress, 
	VA* last_free_space_adress, 
	size_t segment_size
	);

/**
	@func	_init_first_free_adress
	@brief	������������� ������� ������, ������� ����� 
			�������� ��������� ������� ��������
**/
int	_init_adress (VA* adress, size_t content_size);

/**
	@func	_allocate_segment
	@brief	���������� �������� � �������� ������������
**/
int	_allocate_segment (VA* allocationg_adress, size_t size);

/**
	@func	_register_segment
	@brief	���������� ���������� � �������� �
			���������� �������
**/
int	_register_segment (segment* segment);

/**
	@func	_renew_first_free_adress
	@brief	��������� ������ ������ ��������� ������
**/
VA* _first_null_content_adress(
	VA* space,
	VA* starting_adress,
	VA* last_free_space_adress
	);

#endif // !ADRESS_SPACES_H
