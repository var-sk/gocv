//go:build !customenv && !static
// +build !customenv,!static

package gocv

// Changes here should be mirrored in contrib/cgo.go and cuda/cgo.go.

/*
#cgo CXXFLAGS:   --std=c++11
#cgo !windows LDFLAGS: -L/usr/local/lib
#cgo windows  LDFLAGS: -LC:/opencv/opencv_connect_4.8.1/bin
#cgo LDFLAGS: -lgocv
*/
import "C"
