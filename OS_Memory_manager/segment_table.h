#include "adress_spaces.h"

#include <stdbool.h>

/**
	v	- �����������
	va	- ����������� �����
	vas - ����������� �������� ������������

	p	- ����������
	pa	- ���������� �����
	pas - ���������� �������� ������������
	st	- ������� ���������
**/

// ������������ ���������� ������� � ������� ���������
#define _ST_MAX_RECORDS_COUNT 100
#define _NO_SEGMENT -1

// ���, ����������� ������ � ������� ���������
typedef struct
{
	segment*	segment_ptr;
	bool		is_loaded;
}
st_record;

// ���, ����������� ������� ���������
typedef struct
{
	size_t current_records_count;
	uint first_free_index;
	st_record* records;
}
segment_table;

segment_table*	_segment_table;	// ������ �� ��������� ���������� �������
uint _count_of_loaded_segments;

int				_init_segment_table ();
int				_add_record_to_segment_table (segment* segment);
int				_remove_record_from_segment_table (segment* segment);
void			_clear_segment_table ();
void			_clear_segment_table_record (uint index);
segment*		_find_segment_by_starting_adress(VA starting_va);
int				_find_segment_by_inner_adress (VA inner_adress, size_t segment_region_size, segment** found_segment);
st_record*		_find_record (segment* segment);
void			_change_loading_mark (segment* segment, bool is_loaded);

void			_print_segment_table ();