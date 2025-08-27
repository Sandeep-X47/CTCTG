% Qna.pl
% ---------- Sample Routes ----------
% route(Start, End, [IntermediateCities])
route(chennai, mumbai, [direct]).
route(chennai, mumbai, [bangalore]).
route(chennai, mumbai, [hyderabad]).
route(chennai, bangalore, [direct]).
route(chennai, hyderabad, [direct]).
route(chennai, hyderabad, [bangalore]).
route(chennai, kolkata, [direct]).
route(chennai, kolkata, [hyderabad]).
route(chennai, kolkata, [hyderabad, delhi]).
route(chennai, kolkata, [hyderabad, bangalore]).
route(chennai, delhi, [direct]).
route(chennai, delhi, [hyderabad]).
route(chennai, delhi, [hyderabad, mumbai]).
route(chennai, delhi, [bangalore, hyderabad]).
route(mumbai, chennai, [direct]).
route(mumbai, chennai, [bangalore]).
route(mumbai, chennai, [hyderabad]).
route(mumbai, chennai, [bangalore, hyderabad]).
route(mumbai, bangalore, [direct]).
route(mumbai, bangalore, [hyderabad]).
route(mumbai, hyderabad, [direct]).
route(mumbai, hyderabad, [bangalore]).
route(mumbai, delhi, [direct]).
route(mumbai, delhi, [hyderabad]).
route(mumbai, delhi, [hyderabad, bangalore]).
route(mumbai, kolkata, [direct]).
route(mumbai, kolkata, [hyderabad]).
route(mumbai, kolkata, [hyderabad, delhi]).
route(bangalore, chennai, [direct]).
route(bangalore, chennai, [hyderabad]).
route(bangalore, mumbai, [direct]).
route(bangalore, mumbai, [hyderabad]).
route(bangalore, delhi, [direct]).
route(bangalore, delhi, [hyderabad, mumbai]).
route(bangalore, kolkata, [direct]).
route(bangalore, kolkata, [hyderabad, delhi]).
route(bangalore, hyderabad, [direct]).
route(bangalore, hyderabad, [mumbai]).
route(hyderabad, chennai, [direct]).
route(hyderabad, chennai, [bangalore]).
route(hyderabad, bangalore, [direct]).
route(hyderabad, bangalore, [mumbai]).
route(hyderabad, delhi, [direct]).
route(hyderabad, delhi, [mumbai]).
route(hyderabad, mumbai, [direct]).
route(hyderabad, mumbai, [bangalore]).
route(hyderabad, kolkata, [direct]).
route(hyderabad, kolkata, [delhi]).
route(kolkata, chennai, [direct]).
route(kolkata, chennai, [hyderabad]).
route(kolkata, bangalore, [direct]).
route(kolkata, bangalore, [delhi, hyderabad]).
route(kolkata, delhi, [direct]).
route(kolkata, delhi, [hyderabad]).
route(kolkata, mumbai, [direct]).
route(kolkata, mumbai, [hyderabad]).
route(kolkata, hyderabad, [direct]).
route(kolkata, hyderabad, [delhi]).
route(delhi, chennai, [direct]).
route(delhi, chennai, [hyderabad]).
route(delhi, bangalore, [direct]).
route(delhi, bangalore, [mumbai, hyderabad]).
route(delhi, kolkata, [direct]).
route(delhi, kolkata, [hyderabad]).
route(delhi, mumbai, [direct]).
route(delhi, mumbai, [hyderabad]).
route(delhi, hyderabad, [direct]).
route(delhi, hyderabad, [mumbai]).

% ---------- Helper: Convert strings to lowercase ----------
to_lower(Str, Lower) :-
    string_lower(Str, Lower).

% ---------- Check if route exists via a city ----------
% From, To, Via are strings
print_message(From, To, Via) :-
    to_lower(From, FromL),
    to_lower(To, ToL),
    to_lower(Via, ViaL),

    % Check if there is a route from From to To via Via
    (   route(FromAtom, ToAtom, Intermediates),
        atom_string(FromAtom, FromL),
        atom_string(ToAtom, ToL),
        maplist(atom_string, Intermediates, InterStrs),
        maplist(string_lower, InterStrs, InterStrsLower),
        member(ViaL, InterStrsLower)
    ->  format("Yes! There is a route from ~w to ~w via ~w.~n", [From, To, Via])
    ;   format("No route found from ~w to ~w via ~w.~n", [From, To, Via])
    ).
