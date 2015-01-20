import os

# BASE ENVIRONMENT
# Environment that is platform agnostic
baseEnv = Environment()
print baseEnv['PLATFORM']
if baseEnv['PLATFORM'] == 'posix':
    baseEnv.Append(CCFLAGS = [
        '-DHAVE_LINUX',
        '-std=c++98',
        '-pedantic-errors',
        '-Wall',
        '-Wextra',
        '-Wuninitialized',
        '-O'])
if baseEnv['PLATFORM'] == 'win32':
    baseEnv.Append(ENV = {'PATH' : os.environ['PATH']})
    baseEnv.Append(ENV = {'LIB' : os.environ.get('LIB')})
    baseEnv.Append(ENV = {'INCLUDE' : os.environ.get('INCLUDE')})
    baseEnv.Append(CCFLAGS = [
        '-DHAVE_WINDOWS',
        '/W4',
#        '/Wall',
        '/WX',
#        '/Za',
        '/EHsc'])
if baseEnv['PLATFORM'] == 'darwin':
    baseEnv.Append(CCFLAGS = [
        '-DHAVE_OSX'])

# DIST SCTRUCTURE
dist = 'dist/%s' % baseEnv['PLATFORM']
debug = '%s/debug' % dist
baseEnv['DIST'] = '#/%s' % dist
baseEnv['DEBUG'] = '#/%s' % debug
Execute(Mkdir(debug))

Export('baseEnv')

VariantDir('gen', '#', duplicate=0)
SConscript('gen/SConscript')
SConscript('gen/main/SConscript')

