## Old Object

```jsx
var sayNode = function(){
    console.log('Node');
}

var es = 'ES';

var oldObject = {
    sayJS:function(){
        console.log('JS');
    },
    sayNode: sayNode,
};

oldObject[es + 6] = 'Fantastic';
oldObject.sayNode();
oldObject.sayJS();
console.log(oldObject.ES6);
```

## New Object

```jsx
const sayNode = function(){
    console.log('Node');
}

const es = 'ES';

const newObject = {
    sayJS(){
        console.log('JS');
    },
    sayNode,
    [es + 6]:'Fantastic',
};

newObject.sayNode();
newObject.sayJS();
console.log(newObject.ES6);
```

## 비교

- sayJS 같은 객체의 매서드에 함수를 연결할 때 콜론( : )과 function을 붙이지 않아도 된다.
- sayNode: sayNode처럼 속성명과 변수명이 동일한 경우 한 번만 써도 된다.
- 객체의 속성명은 동적으로 생성할 수 있다.