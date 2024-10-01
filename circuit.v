module circuit (input clk, input in, output reg out);
    reg d=0; // Keep as reg if used only in procedural logic
    always @(posedge clk)
        out <= d;
    always @*
        d = in ^ out;
endmodule
