(* Functional statistics using immutable lists and higher-order functions. *)
let mean values =
  let sum = List.fold_left ( + ) 0 values in
  float_of_int sum /. float_of_int (List.length values)

let median values =
  let sorted = List.sort compare values in
  let n = List.length sorted in
  if n mod 2 = 1 then float_of_int (List.nth sorted (n / 2))
  else float_of_int (List.nth sorted (n / 2 - 1) + List.nth sorted (n / 2)) /. 2.0

let modes values =
  let frequencies =
    List.fold_left
      (fun counts x ->
        let old = try List.assoc x counts with Not_found -> 0 in
        (x, old + 1) :: List.remove_assoc x counts)
      [] values
  in
  let highest = List.fold_left (fun best (_, count) -> max best count) 0 frequencies in
  if highest = 1 then ([], highest)
  else
    (frequencies
     |> List.filter (fun (_, count) -> count = highest)
     |> List.map fst
     |> List.sort compare, highest)

let () =
  print_string "How many integers? ";
  let n = read_int () in
  if n <= 0 || n > 10000 then (prerr_endline "Count must be 1..10000"; exit 1);
  print_endline "Enter one integer per line:";
  let rec read_values remaining =
    if remaining = 0 then [] else let x = read_int () in x :: read_values (remaining - 1)
  in
  let values = read_values n in
  Printf.printf "Mean: %.2f\nMedian: %.2f\n" (mean values) (median values);
  let found, frequency = modes values in
  match found with
  | [] -> print_endline "Mode: No mode (all values occur once)"
  | xs ->
      Printf.printf "Mode(s): %s (frequency: %d)\n"
        (String.concat ", " (List.map string_of_int xs)) frequency
