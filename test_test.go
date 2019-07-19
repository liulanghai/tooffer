package tooffer

import "testing"
import . "github.com/smartystreets/goconvey/convey"

func TestFind(t *testing.T) {
	/*
		[1,2,8  9]
		[2,4,9, 12]
		[4,7,10,13]
		[6,8,11,15]
	*/
	arr := [][]int{{1, 2, 3}, {2, 3, 4}, {7, 8, 9}}
	res := findArray(arr, 9)
	res2 := findArray(arr, 0)
	res3 := findArray(arr, 10)
	res4 := findArray(arr, 6)
	res5 := findArray(arr, -1)
	Convey("Subject: findArray \n", t, func() {
		So(res, ShouldEqual, true)
		So(res2, ShouldEqual, false)
		So(res3, ShouldEqual, false)
		So(res4, ShouldEqual, true)
		So(res5, ShouldEqual, false)
	})
}

func TestFibonacci(t *testing.T) {
	//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144,
	Convey("Subject: Fibonacci \n", t, func() {
		So(Fibonacci(1), ShouldEqual, 1)
		So(Fibonacci(2), ShouldEqual, 1)
		So(Fibonacci(4), ShouldEqual, 3)

	})
}

func TestJumpFloor(t *testing.T) {
	//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144,
	Convey("Subject: jumpFloor \n", t, func() {
		So(jumpFloor(1), ShouldEqual, 1)
		So(jumpFloor(2), ShouldEqual, 2)
		So(jumpFloor(3), ShouldEqual, 3)

	})
}
