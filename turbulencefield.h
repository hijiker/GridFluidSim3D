#pragma once

#include <assert.h>

#include "array3d.h"
#include "grid3d.h"
#include "macvelocityfield.h"
#include "glm/glm.hpp"

#include "stopwatch.h"

class TurbulenceField
{
public:
    TurbulenceField();
    ~TurbulenceField();

    void calculateTurbulenceField(MACVelocityField *vfield,
                                  Array3d<int> &matGrid);
    void destroyTurbulenceField();
    double evaluateTurbulenceAtPosition(glm::vec3 p);

private:
    
    void _getVelocityGrid(MACVelocityField *macfield, 
                          Array3d<glm::vec3> &vgrid);
    double _calculateTurbulenceAtGridCell(int i, int j, int k, 
                                          Array3d<glm::vec3> &vgrid);
    double _trilinearInterpolate(double p[8], double x, double y, double z);

    int M_FLUID = 1;

    Array3d<double> _field;

    int _isize, _jsize, _ksize;
    double _dx;
    double _radius;

};
