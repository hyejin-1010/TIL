### factory 생성자 : 싱글톤

factory 키워드를 사용해서 생성자를 구현하면, 해당 클래스의 인스턴스를 항상 새로 만들지 않는다.

> 참고: https://eunjin3786.tistory.com/263

-

### freezed
```
import 'package:flutter/material.dart';
import 'package:freezed_annotation/freezed_annotation.dart';

part 'product.freezed.dart';

@freezed
abstract class Product with _$Product {
  const factory Product({
    String id,
    String name,
    Color color,
  }) = _Product;
}
```

위와 같은 형식으로 코드를 작성한 후, build를 하면 
'product.freezed.dart' 파일이 생성된다.

> 참고: https://developer.school/how-to-use-freezed-with-flutter/
> package: https://pub.dev/packages/freezed
