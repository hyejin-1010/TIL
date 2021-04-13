
### CurvedAnimation
애니메이션의 진행 상황을 비선형 곡선으로 정의한다.

```
animation = CurvedAnimation(parent: conroller, curve: Curves.easeIn);
```
**Curves**는 일반적으로 사용하는 곡선을 정의해 놓은 것이며,
아래와 같이 사용자가 정의할 수 있다.

```
impoert 'dart:math';

class ShakeCurve extends Curve {
	@override
	double transform(double t) => sin(t * pi * 2);
}
```

> CurvedAnimation과 AnimationController는 둘 다 Animation<double> 타입이므로, 서로 바꿔서 전달할 수 있다.

-

### AnimationController
하드웨어가 새로운 프레임을 준비할 때 마다 새로운 값을 생성하는, 특별한 Animation 객체이다.
주어진 기간동안 0.0~1.0사이의 숫자로 선형을 생성한다.

```
controller = AnimationController(
	duration: const Duration(seconds: 2),
	vsync: this
)
```
↑ 위 코드는 Animation 객체를 생성하였지만, 실행을 시작하지는 않았다.

- .forward() 로 애니메이션을 시작한다.
- 숫자 생성은 화면 새로 고침과 관련이 있어, 일반적으로 초당 60개의 숫자가 생성된다.
- 숫자가 생성된 후 각 Animation 객체는 연결된 Listener 개체를 호출한다.
- 각 하위 항목에 대한 custom display list을 만들려면 [RepaintBoundary](https://api.flutter.dev/flutter/widgets/RepaintBoundary-class.html) 을 참고하면 된다.

AnimationController를 생성할 때, **vsync** 인수를 넘긴다.
vsync는 offscreen animation이 불피요한 리소스를 소비하지 못하도록 방지한다.

[example: animate1](https://github.com/flutter/website/tree/master/null_safety_examples/animation/animate1)

-

### Tween
기본적으로 AnimationController의 범위는 0.0에서 1.0까지이다.<br/>
다른 범위 또는 다른 데이터 유형이 필요한 경우 Tween을 사용하여, 다른 범위 또는 데이터 유형으로 애니메이션을 구성할 수 있다.

```
tween = Tween<double>(begin: -200, end: 0);
```
입력 범위는 일반적으로 0.0 ~ 1.0 이지만, 필수 사항은 아니다.

Tween은  Animation<T>가 아닌 Animatable<T>를 상속받는다.
Animation과 같은 Animatable은 두 번 출력되지 않는다.

```
colorTween = ColorTween(begin: Colors.transparent, end: Colors.black54);
```

Tween 객체는 상태를 저장히자 않지만, 대신 애니메이션의 현재 값에 매핑 함수를 적용하는 evaluation(Animation<doubole> animation) 메소드를 제공한다.

Animation 객체의 현재 값은 .value() 메소드를 통해 찾을 수 있다.

```
AnimationController controller = AnimationController(
	duration: const Duration(milliseconds: 500),
	vsync: this
);
Animation<int> alpha = IntTween(begin: 0, end: 255).animate(controller);
```

```
AnumationController controller = AnimationController(
	duration: const Duration(milliseconds: 500),
	vsync: this
);
final Animation<double> curve = CurvedAnimation(
	parent: controller,
	curve: Curves.easeOut,
);
Animation<int> alpha = IntTween(begin: 0, end: 255).animate(curve);
```

[참고: 공식 문서](https://flutter.dev/docs/development/ui/animations/tutorial)