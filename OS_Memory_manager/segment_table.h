#include "adress_spaces.h"

#include <stdbool.h>

//	///////////////////////////////////////
//	va	- ����������� �����
//	vas - ����������� �������� ������������
//
//	p	- ����������
//	pa	- ���������� �����
//	pas - ���������� �������� ������������
//	///////////////////////////////////////

// ������������ ���������� ������� � ������� ���������
#define _ST_MAX_RECORDS_COUNT (_VAS_MAX_SIZE / sizeof(segment))

// ���, ����������� ������ � ������� ���������
typedef struct
{
	segment*	segment_ptr;
	PA			pa;
	bool		is_loaded;
}
st_record;

// ���, ����������� ������� ���������
typedef struct
{
	size_t					current_records_count;
	uint					first_free_index;
	st_record*	records;
}
segment_table;

int			_init_segment_table ();
int			_add_record_to_segment_table (segment* segment);
int			_remove_record_from_segment_table (uint index);
void		_clear_segment_table ();
void		_clear_segment_table_record (uint index);
segment*	_find_segment (VA segment_starting_va);

void		_print_segment_table ();
