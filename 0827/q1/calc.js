// calc.js

// 하드코딩된 입력 값
const a = 2;
const b = 4;

// calc 객체 생성
const calc = {
    add: (x, y) => x + y,
    subtract: (x, y) => x - y,
    multiply: (x, y) => x * y,
    divide: (x, y) => x / y
};

// 연산 결과 출력
console.log(`주어진 수: ${a} ${b}`);
console.log(`덧셈 결과: ${calc.add(a, b)}`);
console.log(`뺄셈 결과: ${calc.subtract(a, b)}`);
console.log(`곱셈 결과: ${calc.multiply(a, b)}`);
console.log(`나눗셈 결과: ${calc.divide(a, b)}`);
