$buildFolderPath = ".\build"

# Check if the build folder already exists
if (-not (Test-Path $buildFolderPath -PathType Container)) {
	# Create the build folder
	New-Item -ItemType Directory -Path $buildFolderPath | Out-Null
	Write-Host "Build folder created successfully."
} else {
	Write-Host "Build folder already exists."
}

cmake -G "MinGW Makefiles" -S . -B .\build\
cmake --build .\build\