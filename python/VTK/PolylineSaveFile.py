#!/usr/bin/python
# This example demonstrates how to create a polyline through several ordered points.

import vtk
import math

# vtkPoints represents 3D points. The data model for vtkPoints is an array of
# vx-vy-vz triplets accessible by (point or cell) id.
points = vtk.vtkPoints()
points.SetNumberOfPoints(6)
c = math.cos(math.pi/6) # helper variable
points.SetPoint(0, 0.0, -1.0, 0.0)
points.SetPoint(1,   c, -0.5, 0.0)
points.SetPoint(2,   c,  0.5, 0.0)
points.SetPoint(3, 0.0,  1.0, 0.0)
points.SetPoint(4,  -c,  0.5, 0.0)
points.SetPoint(5,  -c, -0.5, 0.0)

# vtkCellArray is a supporting object that explicitly represents cell connectivity.
# The cell array structure is a raw integer list of the form:
# (n,id1,id2,...,idn, n,id1,id2,...,idn, ...) where n is the number of points in
# the cell, and id is a zero-offset index into an associated point list.
lines = vtk.vtkCellArray()
lines.InsertNextCell(7)
lines.InsertCellPoint(0)
lines.InsertCellPoint(1)
lines.InsertCellPoint(2)
lines.InsertCellPoint(3)
lines.InsertCellPoint(4)
lines.InsertCellPoint(5)
lines.InsertCellPoint(0)

# vtkPolyData is a data object that is a concrete implementation of vtkDataSet.
# vtkPolyData represents a geometric structure consisting of vertices, lines,
# polygons, and/or triangle strips
polygon = vtk.vtkPolyData()
polygon.SetPoints(points)
polygon.SetLines(lines)

writer = vtk.vtkXMLPolyDataWriter();
writer.SetFileName("Hexagon.vtp");
if vtk.VTK_MAJOR_VERSION <= 5:
  writer.SetInput(polygon)
else:
  writer.SetInputData(polygon)
  writer.Write()


