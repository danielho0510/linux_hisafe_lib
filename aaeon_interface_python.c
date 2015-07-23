#include "/usr/include/python2.7/Python.h"
#include "aaeon_interface.h"
// interface function from Python to C (Python call C)
static PyObject* aaeon_open_superio_py(PyObject *self, PyObject* args) {
	//char *pstr;
	//int a; 
	//float b;
	int result;
	if(!PyArg_ParseTuple(args,"")) return NULL;
	result = aaeon_open_superio();
	return Py_BuildValue("i",result);
}

//static PyObject* Call_CFunction2(PyObject* self, PyObject* args){
//	char* result;
//	long int a;
//	double b;
//	if(!PyArg_ParseTuple(args,"ld",&a,&b)) return NULL;
//	result = CFunction2(a,b);
//	return Py_BuildValue("s",result);
//}

/****************************************************************
　　　* Registration table *
****************************************************************/

static struct PyMethodDef test_methods[] = {
	{"Aaeon_open_superio", aaeon_open_superio_py, 1},
	//{"Method2", Call_CFunction2, 1},
	{ NULL, NULL}
};


/****************************************************************
　　　* Initialization *
****************************************************************/

void initaaeon_interface_py(void) {
	Py_InitModule("aaeon_interface_py", test_methods);
}


