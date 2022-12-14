
#include <rfb/rfb.h>
#include <stdlib.h>

#include "cast_screen.h"
#include "flutter_application.h"

int main(int argc, char* argv[]) {
//  cast::FlutterApplication application(argv[1]);
  auto application = std::make_unique<cast::FlutterApplication>(argv[1]);

  if (!application->IsValid()) {
    CAST_ERROR << "Could not run the Flutter application." << std::endl;
    return EXIT_FAILURE;
  }

  cast::CastScreen screen(std::move(application), "VNC Flutter", 320 * 2,
                          480 * 2);

  if (!screen.IsValid()) {
    CAST_ERROR << "Could not create the cast screen." << std::endl;
    return EXIT_FAILURE;
  }

  screen.Run();

  return EXIT_SUCCESS;
}
