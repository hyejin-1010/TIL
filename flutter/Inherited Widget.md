# [Flutter] Inherited Widget
특정 데이터를 계층 상 아래에 있는 모든 Widget에서 효율적으로 가져갈 수 있게 해주는 특별한 Widget.

``` dart
class _Data extends InheritedWidget {
	final Widget child;
	final _SharedData data;

	_Data({
		this.child,
		this.data,
	}) : assert(child != null),
		 assert(data != null);

	@override
	bool updateShouldNotify(InheritedWidget oldWidget) => false;

	static _ShareData of(BuildContext context) => context.dependOnInheritedWidgetOfExactType<_Data>().data;
}
```

**updateShouldNotify**: InheritedWidget이 어떠한 이유로 인하여 update되었을 떄, 이 InheritedWidget에 의존하는 widget을 rebuild할 지 결정하는 장소.

```dart
final SharedTitle = _Data.of(context).title;;
final sharedChange = _Data.of(context).change;
```
-> widget tree 중 적절한 곳에 끼워넣어주고 필요한 자식 widget에서 자유롭게 `of`라는 static method를 통해 가져오면 된다.

> 참고: [Puppyloper’s Blog](https://blog.puppyloper.com/menus/Flutter/articles/Inherited%20widget%EC%9D%B4%20%EB%AD%90%EC%A7%80%3F)  