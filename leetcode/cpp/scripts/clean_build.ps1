# @usage
# Make sure to set current execution policy to RemoteSigned or Unrestricted
# Get-ExecutionPolicy
# Set-ExecutionPolicy RemoteSigned

$buildFolderPath = ".\build\"

if (-not (Test-Path $buildFolderPath -PathType Container)) {
	Write-Host "Build folder is not found."
} else {
    Remove-Item $buildFolderPath/* -Recurse -Force
}