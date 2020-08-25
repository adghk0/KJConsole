#pragma once

// Arraylist class
// 동적 배열 클래스
template<typename T>
class ArrayList {
private:
	// the variable of data;
	// 데이터 변수
	T* array;
	// the length of array
	// 배열의 길이
	int length;

public:
	// constructor
	// 생성자
	ArrayList() {
		// assign spaces in memory
		// 메모리 할당
		length = 0;
		array = (T*)malloc(sizeof(T) * length);
	}
	// destructor
	// 소멸자
	~ArrayList() {
		// return spaces in memory
		// 메모리 반환
		free(array);
	}

	// return the size of array
	// 배열 크기 반환
	int size() { return length; }

	// get all array
	// 전체 값 가져오기
	T* get() { return array; }
	// get value at index
	// 다음 위치의 값 가져오기
	T get(int index) { return array[index]; }

	// add data at the end
	// 맨 뒤에 값 추가
	bool add(T data);
	// add data at index
	// 다음 위치에 값 추가
	bool add(T data, int index);
	// set data at index
	// 다음 위치 값 변경
	bool set(T data, int index);
	// delete data at index
	// 다음 위치 값 제거
	bool del(int index);

	// get the first data
	// 맨 처음 값 가져오기
	T getFirst() { return get(0); }
	// get the last data
	// 맨 마지막 값 가져오기
	T getLast() { return get(length - 1); }
	// delete the first data
	// 맨 처음 값 제거
	bool delFirst() { return del(0); }
	// delete the last data
	// 맨 마지막 값 제거
	bool delLast() { return del(length - 1); }

	// make a new object which is same as this 
	// 동일한 객체 생성
	ArrayList<T>* clone();
};

template<typename T>
inline bool ArrayList<T>::add(T data)
{
	// 길이 1증가
	length++;
	array = (T*)realloc(array, length * sizeof(T));

	array[length - 1] = data;
	return true;
}
template<typename T>
inline bool ArrayList<T>::add(T data, int index)
{
	if (index < 0 || index > length) // 인덱스 범위를 벗어남 (0 <= index <= length)
		return false;

	// 길이 1증가
	length++;
	array = (T*)realloc(array, length * sizeof(T));

	// index 이후 내용 이동
	memmove(array + index + 1, array + index, sizeof(T) * (length - index));

	array[index] = data;
	return true;
}

template<typename T>
inline bool ArrayList<T>::set(T data, int index)
{
	if (index < 0 || index >= length) // 인덱스 범위를 벗어남 (0 <= index < length)
		return false;

	array[index] = data;
	return true;
}
template<typename T>
inline bool ArrayList<T>::del(int index)
{
	if (index < 0 || index >= length) // 인덱스 범위를 벗어남 (0 <= index < length)
		return false;

	length--;

	// index 이후 값 이동
	memmove(array + index, array + index + 1, sizeof(T) * (length - index));
	array = (T*)realloc(array, length * sizeof(T));

	return true;
}
template<typename T>
inline ArrayList<T>* ArrayList<T>::clone()
{
	// 새로운 객체 생성
	ArrayList<T>* cl = new ArrayList<T>();
	// 멤버 변수 설정
	cl->length = length;
	cl->array = (T*)realloc(cl->array, length * sizeof(T));
	// 값 복사
	memcpy(cl->array, array, length * sizeof(T));
	return cl;
}
