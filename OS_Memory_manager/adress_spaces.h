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

#define PAS_MAX_SIZE 1024			// ������������ ������ ����������� ��������� ������������ (� ������)
#define VAS_MAX_SIZE PAS_MAX_SIZE	// ������������ ������ ������������ ��������� ������������ (� ������)
#define NULL_MEMORY_INDEX -1		// ������ ������, ������� ��������� ��� ������

PA _pas[PAS_MAX_SIZE];				// ���������� �������� ������������
VA _vas[VAS_MAX_SIZE];				// ����������� �������� ������������

size_t _pas_size;
size_t _vas_size;

int _first_free_va_index;
int _first_free_pa_index;

VA		_init_vas (size_t size);
PA		_init_pas (size_t size);
VA		_allocate_segment (size_t size);
void	_defragment_vas ();

void _print_vas ();
void _print_pas ();