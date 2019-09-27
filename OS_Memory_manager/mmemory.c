#include "mmemory.h"
#include "segment_table.h"
#include "adress_spaces.h"

#include <stdlib.h>
#include <stdbool.h>

/**
	@func	_malloc
	@brief	�������� ���� ������ ������������� �������

	@param	[out] ptr		������ �����
	@param	[in]  szBlock	������ �����

	@return	��� ������
	@retval	0	�������� ����������
	@retval	-1	�������� ���������
	@retval	-2	�������� ������
	@retval	1	����������� ������
 **/
int _malloc (VA* ptr, size_t szBlock)
{
	if (*ptr == NULL)
	{
		return _WRONG_PARAMS;
	}



	return _SUCCESS;
}



/**
	@func	_free
	@brief	�������� ����� ������

	@param	[in] ptr		������ �����

	@return	��� ������
	@retval	0	�������� ����������
	@retval	-1	�������� ���������
	@retval	1	����������� ������
 **/
int _free(VA ptr) {
	if (_find_segment(ptr) != NULL) 
	{
		

		return _SUCCESS;
	}

	return _WRONG_PARAMS;
}



/**
	@func	_read
	@brief	������ ���������� �� ����� ������

	@param	[in] ptr		������ �����
	@param	[in] pBuffer	������ ������ ���� ���������� ���������
	@param	[in] szBuffer	������ ������

	@return	��� ������
	@retval	0	�������� ����������
	@retval	-1	�������� ���������
	@retval	-2	������ �� ������� �����
	@retval	1	����������� ������
 **/
int _read(VA ptr, void* pBuffer, size_t szBuffer) 
{

}



/**
	@func	_write
	@brief	������ ���������� � ���� ������

	@param	[in] ptr		������ �����
	@param	[in] pBuffer	������ ������ ���� ���������� ���������
	@param	[in] szBuffer	������ ������

	@return	��� ������
	@retval	0	�������� ����������
	@retval	-1	�������� ���������
	@retval	-2	������ �� ������� �����
	@retval	1	����������� ������
 **/
int _write(VA ptr, void* pBuffer, size_t szBuffer) 
{

}



/**
	@func	_init
	@brief	������������� ������ ��������� ������

	@param	[in] n		���������� �������
	@param	[in] szPage	������ ��������

	� �������� 1 � 2 ����� ����� ������ ������������� ��� n*szPage

	@return	��� ������
	@retval	0	�������� ����������
	@retval	-1	�������� ���������
	@retval	1	����������� ������
 **/
int _init(int n, int szPage) 
{
	if (_init_pas(n * szPage) == _WRONG_PARAMS)
	{
		return _WRONG_PARAMS;
	}

	if (_init_vas(n * szPage) == _WRONG_PARAMS)
	{
		return _WRONG_PARAMS;
	}

	_init_segment_table();

	return _SUCCESS;
}