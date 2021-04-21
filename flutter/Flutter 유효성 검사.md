
## Flutter 유효성 검사

- 확인하려는 값에 따라 에러 또는 성공 결과 값 노출

### if-else
if-else문으로는 컨텍스트를 풍부하게 표현하기 어렵다.<br />
객체의 이점을 드러내기 어렵다.

### 예외(Exception)를 사용하여 의미를 더 부여
try-catch를 이용하여 Exception 처리

- Exception이 결과 타입에 드러나지 않는다.
- try, catch로 감사는 걸 깜빡하면 어디서 예외가 잡힐 지 찾아야 한다.

'Exception을 값처럼 반환하면 되지 않을까?'

### Either
- ```(T value) => Either<E, T>```

### Union
- 각각에 대한 처리는 when 혹은 map을 사용해 처리한다.

> https://www.youtube.com/watch?v=9E6EeIzp2FQ