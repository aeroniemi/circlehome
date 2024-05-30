# source from https://github.com/MobiFlight/MobiFlight-FirmwareSource/blob/main/get_version.py

Import("env")
import os

# Get the version number from the build environment.
version = os.environ.get('VERSION', "")

# Clean up the version number
if version == "":
  # When no version is specified default to "0.0.1"
  version = "0.0.1"

# Strip any leading "v" that might be on the version and
# any leading or trailing periods.
version = version.lstrip("v")
version = version.strip(".")

print(f'Using version {version} for the build')

# Append the version to the build defines so it gets baked into the firmware
env.Append(CPPDEFINES=[
  f'BUILD_VERSION={version}'
])