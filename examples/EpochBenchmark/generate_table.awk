#!/usr/bin/gawk -f
#
# Usage: generate_table.awk < ${board}.txt
#
# Takes the *.txt file generated by EpochBenchmark.ino and generates an ASCII
# table that can be inserted into the README.md.

BEGIN {
  # Set to 1 when 'BENCHMARKS' is detected
  collect_benchmarks = 0
}

/^BENCHMARKS/ {
  collect_benchmarks = 1
  benchmark_index = 0
  next
}

!/^END/ {
  if (collect_benchmarks) {
    u[benchmark_index]["name"] = $1
    u[benchmark_index]["micros"] = $2
    u[benchmark_index]["iterations"] = $3
    benchmark_index++
  }
}

END {
  TOTAL_BENCHMARKS = benchmark_index

  # Calculate the diff from baseline
  baseline = u[0]["micros"]
  for (i = 0; i < TOTAL_BENCHMARKS; i++) {
    u[i]["diff"] = u[i]["micros"] - baseline
  }

  printf("+----------------------------------------+-------------+----------+\n")
  printf("| Algorithm                              | micros/iter |     diff |\n")

  for (i = 0; i < TOTAL_BENCHMARKS; i++) {
    name = u[i]["name"]
    if (name ~ /^EmptyLoop$/ \
        || name ~ /^EpochConverterJulian$/ \
    ) {
      printf(\
        "|----------------------------------------+-------------+----------|\n")
    }
    printf("| %-38s |    %8.3f | %8.3f |\n", name, u[i]["micros"], u[i]["diff"])
  }
  printf("+----------------------------------------+-------------+----------+\n")
}
