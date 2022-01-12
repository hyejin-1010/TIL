# Sorting (정렬)
* n 개의 숫자가 입력으로 주어졌을 때, 이를 사용자가 지정한 기준에 맞게 정렬하여 출력하는 알고리즘.

## Selection Sort (선택 정렬)
* 현재 위치에 들어갈 값을 찾아 정렬하는 배열.
* 위치에 저장될 값의 크기가 작냐, 크냐에 따라 최소 선택 정렬(Min-Selection Sort, 오름차순), 최대 선택 정렬(Max-Selection Sort, 내림차순) 로 구분.

### 기본 로직
1. 맨 앞 index 부터, 이를 포함한 그 이후 배열 값 중 가장 작은 값을 찾아, 그 값을 현재 index 의 값과 바꿔준다.
2. 다음 index 에서 위 과정을 반복한다.

* **시간 복잡도** : O(n^2) / Best : O(n^2)
* **공간 복잡도** : O(n)

``` javascript
void selectionSort (array) {
	for (let i = 0; i < array.length; i ++) {
		int temp = i;
		for (let j = i + 1; j < array.length; j ++) {
			if (array[temp] >= array[j]) { temp = j; }
		}
		int value = array[temp];
		array[temp] = array[i];
		array[i] = value;
	}
}
```


- - - -

## Insertion Sort (삽입 정렬)
* 현재 위치에서, 그 이하의 배열들을 비교하여 자신이 들어갈 위치를 찾아 그 위치에 삽입하는 알고리즘.

### 기본 로직
1. 두 번째 index부터 시작한다. 현재 index는 별도의 인수에 저장해주고, 비교 index를 현재 index - 1 로 잡는다.
2. 별도로 저장해둔 삽입을 위한 변수와 비교 index의 값을 비교한다.
3. 삽입 변수의 값이 더 작은 경우 현재 index로 비교 index의 값을 저장해주고, 비교 인덱스를 -1 하여 비교를 반복한다.
4. 만약 삽입 변수가 더 크면, 비교 index + 1 에 삽입 변수를 저장한다.

* **시간 복잡도** : O(n^2) / Best : O(n)
* **공간 복잡도** : O(n^2)

``` javascript
void insertionSort (array) {
	for (int i = 1; i < array.length; i ++) {
		let key = array[i];
		let j = i - 1;
		while (j >= 0 && key < array[j]) {
			array[j + 1] = array[j];
			j --;
		}
		array[j + 1] = key;
	}
}
```


- - - -

## Bubble Sort (버블 정렬)
* 매번 연속된 두 개 index를 비교하여, 정한 기준의 값을 뒤로 넘기는 정렬.

### 기본 로직
1. 두 번째 index부터 시작한다.
2. 현재 index 값과, 바로 이전의 index 값을 비교한다.
3. 이전 index 가 더 크면, 현재 index와 바꿔준다. 현재 index가 더 크면 교환하지 않는다.
4. 다음 두 연속된 배열 값을 배교한다.
5. 이를 (전체 배열의 크기 - 현재까지 순환한 바퀴수) 만큼 반복한다.

* **시간 복잡도** : O(n^2)
* **공간 복잡도** : O(n)

``` javascript
void bubbleSort (array) {
	for (int i = 0; i < array.length - 1; i ++) {
		for (int j = 1; j < array.length - 1; j ++) {
			if (array[j - 1] > array[j]) {
				int value = array[j - 1];
				array[j - 1] = array[j];
				array[j] = value;
			}
		}
	}
}
```


