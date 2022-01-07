#include <vtkVersion.h>
#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>

#include <sstream>

#include <vtkPolyData.h>
#include <vtkSTLWriter.h>
#include <string>
#include <vtkLine.h>
#include <vtkCellArray.h>


int main(int argc, char* argv[])
{
  std::string outfilename = "joder.vtk";

  // Verify input arguments
  if ( argc != 2 )
  {
    std::cout << "Usage: " << argv[0]
              << " Filename(.xyz)" << std::endl;
    return EXIT_FAILURE;
  }
  // Get all data from the file
  std::string filename = argv[1];
  std::ifstream filestream(filename.c_str());

  std::string line;
  vtkSmartPointer<vtkPoints> points =
    vtkSmartPointer<vtkPoints>::New();

  while(std::getline(filestream, line))
  {
    double x, y, z;
    std::stringstream linestream;
    linestream << line;
    linestream >> x >> y >> z;

    points->InsertNextPoint(x, y, z);
  }

  filestream.close();

  // Create a cell array to store the lines in and add the lines to it
  vtkSmartPointer<vtkCellArray> lines =
    vtkSmartPointer<vtkCellArray>::New();

  for(unsigned int i = 0; i < 800; i++)
  {
    vtkSmartPointer<vtkLine> line =
      vtkSmartPointer<vtkLine>::New();
    line->GetPointIds()->SetId(0,i);
    line->GetPointIds()->SetId(1,i+1);
    lines->InsertNextCell(line);
  }


  vtkSmartPointer<vtkPolyData> polyData =
    vtkSmartPointer<vtkPolyData>::New();

  polyData->SetPoints(points);
  
  // Add lines
  polyData->SetLines(lines);

  // Write a file
  vtkSmartPointer<vtkSTLWriter> stlWriter =
    vtkSmartPointer<vtkSTLWriter>::New();
  //stlWriter->SetFileTypeToASCII ();
  stlWriter->SetFileName(outfilename.c_str());
  stlWriter->SetInputData(polyData);
  //stlWriter->SetInputConnection(polyData->GetOutputPort());
  stlWriter->Write();

/*
  vtkSmartPointer<vtkVertexGlyphFilter> glyphFilter =
    vtkSmartPointer<vtkVertexGlyphFilter>::New();
#if VTK_MAJOR_VERSION <= 5
  glyphFilter->SetInputConnection(polyData->GetProducerPort());
#else
  glyphFilter->SetInputData(polyData);
#endif
  glyphFilter->Update();

  // Visualize

  vtkSmartPointer<vtkPolyDataMapper> mapper =
    vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(glyphFilter->GetOutputPort());

  vtkSmartPointer<vtkActor> actor =
    vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);

  vtkSmartPointer<vtkRenderer> renderer =
    vtkSmartPointer<vtkRenderer>::New();
  renderer->AddActor(actor);
  renderer->SetBackground(.3, .6, .3); // Background color green

  vtkSmartPointer<vtkRenderWindow> renderWindow =
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);

  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);

  renderWindowInteractor->Start();
*/

  return EXIT_SUCCESS;
}
