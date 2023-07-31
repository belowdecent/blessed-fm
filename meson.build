project('blessed-fm', 'c')

sdl2_dep = dependency('sdl2')
sdl2_ttf_dep = dependency('sdl2_ttf')

executable(
  'blessed-fm', 
  [
    'blessed-fm.c', 
    'text/core.c',
    'fs/core.c',
    'fs/list.c'
  ], 
  dependencies: [sdl2_dep, sdl2_ttf_dep])

