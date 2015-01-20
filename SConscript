Import('baseEnv')
env = baseEnv.Clone()

libObjs = []

if baseEnv['PLATFORM'] == 'posix':
    libObjs += SConscript('linux/SConscript')
elif baseEnv['PLATFORM'] == 'win32':
    libObjs += SConscript('windows/SConscript')
elif baseEnv['PLATFORM'] == 'darwin':
    libObjs += SConscript('osx/SConscript')

libObjs += env.Object(Glob('*.cpp'))
env.Library('processlist', libObjs)

