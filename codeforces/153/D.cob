       Program-ID.D.
       Data Division.
       Working-Storage Section.
       01    s    Pic    X(12).
       01    t    Pic    X(12).
       01    a    Pic    S9(12).
       Procedure    Division.
       Accept s.
       string s(7:4) s(4:2) s(1:2) into t.
       Accept s.
       Move s to a.
       Compute a=a+function Integer-of-Date(t).
       Move function Date-of-Integer(a) to s.
       Display s(7:2) "." s(5:2) "." s(1:4).
       Stop run.