#include "mmemory.h"

//	///////////////////////////////////////
//	va	- ����������� �����
//	vas - ����������� �������� ������������
//
//	p	- ����������
//	pa	- ���������� �����
//	pas - ���������� �������� ������������
//	///////////////////////////////////////

#ifndef ADRESS_SPACES_H
#define ADRESS_SPACES_H

// ���, ����������� ���������� �����
typedef char* PA;

// ���, ����������� ������� ������ // ����� ������� � adress_spaces.h
typedef struct
{
	VA		starting_va;
	size_t	size;
}
segment;

#define _PAS_MAX_SIZE 1024				// ������������ ������ ����������� ��������� ������������ (� ������)
#define _VAS_MAX_SIZE _PAS_MAX_SIZE		// ������������ ������ ������������ ��������� ������������ (� ������)

PA* _pas;						// ���������� �������� ������������
VA* _vas;						// ����������� �������� ������������

size_t		_pas_size;					// ������� ������ ����������� ��������� ������������
size_t		_vas_size;					// ������� ������ ������������ ��������� ������������

PA			_first_free_pa;
VA			_first_free_va;

PA			_last_free_pa;
VA			_last_free_va;

int			_init_pas(size_t size);
int			_init_vas(size_t size);
PA			_validate_pa(PA va);
VA			_validate_va(VA va);
segment* _find_segment(VA starting_va);
void		_defragment_vas();

void		_print_vas();
void		_print_pas();


#endif // !ADRESS_SPACES_H

