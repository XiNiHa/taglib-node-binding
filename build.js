const spawn = require("cross-spawn");
const npmRunPath = require("npm-run-path");

const runtime = process.env.npm_config_runtime || "node";
const target = process.env.npm_config_target || process.versions.node;
const abi = process.env.npm_config_abi || process.versions.modules;

const cmake = spawn("cmake-js", [
  "rebuild", "-r", runtime, "-v", target, "--abi", abi
], {
  env: npmRunPath.env()
});

cmake.stdout.pipe(process.stdout);
cmake.stderr.pipe(process.stderr);
cmake.on("exit", (code) => process.exit(code));
