#include "mmemory.h"

//	///////////////////////////////////////
//	va	- ����������� �����
//	vas - ����������� �������� ������������
//
//	p	- ����������
//	pa	- ���������� �����
//	pas - ���������� �������� ������������
//	///////////////////////////////////////

typedef char* PA;					// ���, ����������� ���������� �����

#define _PAS_MAX_SIZE 1024			// ������������ ������ ����������� ��������� ������������ (� ������)
#define _VAS_MAX_SIZE _PAS_MAX_SIZE	// ������������ ������ ������������ ��������� ������������ (� ������)
#define _NULL_MEMORY_INDEX -1		// ������ ������, ������� ��������� ��� ������

PA _pas[_PAS_MAX_SIZE];				// ���������� �������� ������������
VA _vas[_VAS_MAX_SIZE];				// ����������� �������� ������������

size_t _pas_size;
size_t _vas_size;

int _first_free_va_index;
int _first_free_pa_index;

int		_init_vas (size_t size);
int		_init_pas (size_t size);
VA		_validate_va (VA va);
PA		_validate_pa (PA va);
VA		_allocate_segment (size_t size);
void	_defragment_vas ();

void	_print_vas ();
void	_print_pas ();