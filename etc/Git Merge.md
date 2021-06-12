# Git Merge

## Squash and Merge
commit을 합쳐서 새로운 commit을 만들어 merge 한다.
branch의 commit history를 합쳐서 깔끔하게 만들기 위해 사용된다.
```git
$ git checkout master
$ git merge --squash my-branch
$ git commit -m 'commit-messsage'
```

![](Git%20Merge/img1.daumcdn.jpg)


## Rebase and Merge
모든 commit이 합쳐지지 않고, 각각 main branch에 추가된다.
각 commit 은 모두 하나의 parent를 가진다.
Merge commit 기록이 남지 않는다. -> 하나의 branch에서 작업한 것처럼 보여진다.
```git
$ git checkout my-branch
$ git rebase master
$ git checkout master
$ git merge my-branch
```

![](Git%20Merge/img1.daumcdn.jpg)

> 참고: [Git Merge 이해하기 (Merge / Squash and Merge / Rebase and Merge) :: Code Playground](https://im-developer.tistory.com/182)  